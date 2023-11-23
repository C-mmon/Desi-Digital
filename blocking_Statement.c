std::atomic<bool> stop{false};
std::mutex mutex;
std::condition_variable signal;

// consumer thread(s)
while( true )
{
  std::unique_lock lock{ mutex };
  signal.wait( lock );
  if( stop.load() ) {
      break;
  }
  std::cout << "Signaled\n";
}

// producer thread(s)
using namespace std::chrono_literals;
while( !stop.load() )
{
    signal.notify_one();
    std::this_thread::wait_for( 100ms );
}

// main thread
using namespace std::chrono_literals;
std::this_thread::wait_for( 5s );
stop.store( true );
signal.notify_all();