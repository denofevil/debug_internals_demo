events = [:line, :class, :end, :call, :return, :c_call, :c_return, :b_call, :b_return]
trace = TracePoint.new(*events) do |tp|
  # printf "%8s %s:%-2d %15s %8s\n", tp.event, tp.path, tp.lineno, tp.method_id, tp.defined_class
  tp.binding
end

trace.enable