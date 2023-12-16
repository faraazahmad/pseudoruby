all:
	gcc -I/Users/faraaz/.rbenv/versions/3.2.2/include/ruby-3.2.0 -I/Users/faraaz/.rbenv/versions/3.2.2/include/ruby-3.2.0/x86_64-darwin22 -L/Users/faraaz/.rbenv/versions/3.2.2/lib -lruby main.c -o pseudoruby
