class Player < ApplicationRecord
  belongs_to :college, optional: true
  belongs_to :user

  validates :name, presence: true, length: { maximum: 250 }
  validates :phone, presence: true, mobile_number: true
  validates :stage, presence: true, numericality: { greater_than_or_equal_to: 0 }

  include ActiveModel::Validations
  validates_with CollegeIdOrTextValidator
end