require 'benchmark'
require './sample'

# set_trace_func
# require './set_trace_func'

# debug_event_hook
require './debug_event_hook.build'
require './debug_event_hook'

# event_hook gem
# require './event_hook_gem'

# TracePoint
# require './trace_point'

puts Benchmark.measure { our_action }