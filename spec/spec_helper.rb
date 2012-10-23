# Require all extensions up front. They'll also assist in
# writing tests.
Dir[File.join(File.dirname(__FILE__), '..', 'lib', 'extensions', '*.rb')].each {|file| require file }

# Clean test output.
require "minitest/reporters"
MiniTest::Reporters.use!
