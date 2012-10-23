require 'minitest/autorun'
require_relative '../spec_helper'
require_relative '../../lib/extensions/object'

describe Object do
  describe "#blank?" do
    it "returns true when object is nil" do
      nil.blank?.must_equal true
    end
    it "returns true when object is an empty array" do
      [].blank?.must_equal true
    end
    it "returns true when object is an empty string" do
      "".blank?.must_equal true
    end
    it "returns false when object is 0" do
      0.blank?.must_equal false
    end
    it "returns false when object is a non-empty string" do
      "frothy".blank?.must_equal false
    end
    it "returns false when object is a non-empty array" do
      [4, 8, 15, 16, 23, 42].blank?.must_equal false
    end
  end
  
  describe "#present?" do
    it "returns false when object is nil" do
      nil.present?.must_equal false
    end
    it "returns false when object is an empty array" do
      [].present?.must_equal false
    end
    it "returns false when object is an empty string" do
      "".present?.must_equal false
    end
    it "returns true when object is 0" do
      0.present?.must_equal true
    end
    it "returns true when object is a non-empty string" do
      "frothy".present?.must_equal true
    end
    it "returns true when object is a non-empty array" do
      [4, 8, 15, 16, 23, 42].present?.must_equal true
    end
  end
end
