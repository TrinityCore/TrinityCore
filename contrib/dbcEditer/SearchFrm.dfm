object FrmSearch: TFrmSearch
  Left = 261
  Top = 194
  Width = 324
  Height = 215
  Caption = 'Seach F3 Seach Next'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lbseach: TLabel
    Left = 48
    Top = 16
    Width = 57
    Height = 17
    AutoSize = False
    Caption = 'Input:'
  end
  object rgSI: TRadioGroup
    Left = 64
    Top = 40
    Width = 185
    Height = 97
    Caption = 'Seach Dir'
    ItemIndex = 1
    Items.Strings = (
      'Seach up'
      'Seach down'
      'Seach up Current rol'
      'Seach down Current rol')
    TabOrder = 0
  end
  object edSeach: TEdit
    Left = 120
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object btOk: TButton
    Left = 64
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 2
    OnClick = btOkClick
  end
  object btCancel: TButton
    Left = 176
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = btCancelClick
  end
end
