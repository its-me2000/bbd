object Form5: TForm5
  Left = 1048
  Top = 262
  BorderStyle = bsToolWindow
  Caption = 'Keisti porto reik'#353'm'#281
  ClientHeight = 120
  ClientWidth = 148
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
    Left = 16
    Top = 32
    Width = 50
    Height = 13
    Caption = 'Prievadas:'
  end
  object Label2: TLabel
    Left = 64
    Top = 56
    Width = 6
    Height = 13
    Caption = 'h'
  end
  object Label3: TLabel
    Left = 88
    Top = 32
    Width = 44
    Height = 13
    Caption = 'Reik'#353'm'#279':'
  end
  object Label4: TLabel
    Left = 136
    Top = 56
    Width = 6
    Height = 13
    Caption = 'h'
  end
  object Edit1: TEdit
    Left = 16
    Top = 48
    Width = 41
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 4
    TabOrder = 0
    Text = 'AAAA'
    OnChange = Edit1Change
  end
  object Edit2: TEdit
    Left = 88
    Top = 48
    Width = 41
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 4
    TabOrder = 1
    Text = 'AAAA'
    OnChange = Edit2Change
    OnKeyPress = Edit2KeyPress
  end
  object RadioButton1: TRadioButton
    Left = 16
    Top = 8
    Width = 41
    Height = 17
    Caption = 'IN'
    Checked = True
    TabOrder = 2
    TabStop = True
  end
  object RadioButton2: TRadioButton
    Left = 88
    Top = 8
    Width = 41
    Height = 17
    Caption = 'OUT'
    TabOrder = 3
  end
  object Button1: TButton
    Left = 8
    Top = 88
    Width = 65
    Height = 25
    Caption = 'At'#353'aukti'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 80
    Top = 88
    Width = 65
    Height = 25
    Caption = 'Keisti'
    TabOrder = 5
    OnClick = Button2Click
  end
end
