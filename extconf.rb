require "mkmf"

makefile_path = File.join("Makefile")
config = RbConfig::CONFIG
RUBY_LIBDIR = config["libdir"]
RUBY_HDRDIR = config["rubyhdrdir"]
RUBY_ARCHDIR = "#{RUBY_HDRDIR}/x86_64-darwin22"
INPUT_FILE = "main.c"
OUTPUT_FILE = "antiruby"

makefile_str = <<~MFILE
all:
\tgcc -I#{RUBY_HDRDIR} -I#{RUBY_ARCHDIR} -L#{RUBY_LIBDIR} -lruby #{INPUT_FILE} -o #{OUTPUT_FILE}
MFILE

File.open(makefile_path, "w") do |f|
  f.puts makefile_str
end
