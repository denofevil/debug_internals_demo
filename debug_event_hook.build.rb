require 'mkmf'

def build_native(extension_name)
  dir_config(extension_name)
  create_makefile(extension_name)
  `make; rm Makefile; rm #{extension_name}.o`
end

build_native 'debug_event_hook'
