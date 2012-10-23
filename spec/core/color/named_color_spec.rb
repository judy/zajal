require 'minitest/autorun'
require_relative '../../spec_helper'
require_relative '../../../lib/core/color'

describe Color::NamedColor do
  subject {Color::NamedColor.new(:steel_blue, 40)}

  describe "#to_hash" do
    it "should return the name and opacity in a hash" do
      subject.to_hash.must_equal({name: :steel_blue, a: 40})
    end
  end

  describe "#to_rgb" do
    it "should create a new Color::Rrb instance matching the named color" do
      subject.to_rgb.to_a.must_equal [70, 130, 180, 40]
    end
  end
end
