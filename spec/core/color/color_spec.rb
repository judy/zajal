require_relative '../../spec_helper'
require_relative '../../../lib/core/color/color'
require_relative '../../../lib/core/color/rgb'

describe Color do
  describe "#new" do
    it "should create a new Color::RGB instance given RGBA values" do
      Color.new(1, 2, 3, 4).should be_kind_of(Color::RGB)
    end
  end
end
