object Form4: TForm4
  Left = 936
  Top = 146
  BorderStyle = bsToolWindow
  Caption = 'Keisti atminties reik'#353'mes'
  ClientHeight = 167
  ClientWidth = 208
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 12
    Width = 56
    Height = 13
    Caption = 'Segmentas:'
  end
  object Label2: TLabel
    Left = 128
    Top = 12
    Width = 6
    Height = 13
    Caption = 'h'
  end
  object Label3: TLabel
    Left = 16
    Top = 68
    Width = 38
    Height = 13
    Caption = 'Adresai:'
  end
  object Label4: TLabel
    Left = 168
    Top = 68
    Width = 6
    Height = 13
    Caption = 'h'
  end
  object Label6: TLabel
    Left = 111
    Top = 69
    Width = 3
    Height = 13
    Caption = '-'
  end
  object Label7: TLabel
    Left = 16
    Top = 100
    Width = 44
    Height = 13
    Caption = 'Reik'#353'me:'
  end
  object Label8: TLabel
    Left = 96
    Top = 100
    Width = 6
    Height = 13
    Caption = 'h'
  end
  object Edit1: TEdit
    Left = 80
    Top = 8
    Width = 41
    Height = 21
    Hint = 'segmentas Hex formatu'
    CharCase = ecUpperCase
    MaxLength = 4
    TabOrder = 0
    Text = '0000'
    OnChange = Edit1Change
  end
  object RadioButton1: TRadioButton
    Left = 16
    Top = 40
    Width = 89
    Height = 17
    Caption = 'Viena reik'#353'm'#279
    Checked = True
    TabOrder = 1
    TabStop = True
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 120
    Top = 40
    Width = 81
    Height = 17
    Caption = 'U'#382'pildymas'
    TabOrder = 2
    OnClick = RadioButton2Click
  end
  object Edit2: TEdit
    Left = 64
    Top = 64
    Width = 41
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 4
    TabOrder = 3
    Text = '0000'
    OnChange = Edit2Change
  end
  object Edit3: TEdit
    Left = 120
    Top = 64
    Width = 41
    Height = 21
    CharCase = ecUpperCase
    Enabled = False
    MaxLength = 4
    TabOrder = 4
    Text = '0000'
    OnChange = Edit3Change
  end
  object Edit4: TEdit
    Left = 64
    Top = 96
    Width = 25
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 2
    TabOrder = 5
    Text = '00'
    OnChange = Edit4Change
  end
  object Button1: TButton
    Left = 16
    Top = 136
    Width = 75
    Height = 25
    Caption = 'At'#353'aukti'
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 120
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Keisti'
    TabOrder = 7
    OnClick = Button2Click
  end
end
