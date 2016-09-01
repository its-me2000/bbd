object Form6: TForm6
  Left = 1028
  Top = 220
  BorderStyle = bsToolWindow
  Caption = 'Pereiti prie adreso'
  ClientHeight = 78
  ClientWidth = 167
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 120
    Top = 20
    Width = 6
    Height = 13
    Caption = 'h'
  end
  object LabeledEdit1: TLabeledEdit
    Left = 64
    Top = 16
    Width = 49
    Height = 21
    CharCase = ecUpperCase
    EditLabel.Width = 41
    EditLabel.Height = 13
    EditLabel.Caption = 'Adresas:'
    LabelPosition = lpLeft
    LabelSpacing = 3
    MaxLength = 5
    TabOrder = 0
    OnChange = LabeledEdit1Change
    OnKeyPress = LabeledEdit1KeyPress
  end
  object Button1: TButton
    Left = 8
    Top = 48
    Width = 75
    Height = 25
    Caption = 'At'#353'aukti'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 88
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Pereiti'
    TabOrder = 2
    OnClick = Button2Click
  end
end
