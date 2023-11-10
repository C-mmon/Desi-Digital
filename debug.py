    def _handle_line(self, frame: types.FrameType):
        if self._should_break_at(frame):
            self._breakpoint()
  
    def _dispatch_trace(self, frame: types.FrameType, event, arg):
        if self.is_first_call and self._main_file == Path(frame.f_code.co_filename):
            self.is_first_call = False
            self._breakpoint()
            return
        if event == 'call':
            if self._has_break_point_in(frame.f_code):
                if event == 'line' or event == 'call':
                    self._handle_line(frame)
                elif event == 'return' or event == 'exception':
                    self._handle_return(frame)

    def run(self, file: Path):
        # ...
        sys.settrace(self._dispatch_trace)
        # ...