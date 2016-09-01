object Form7: TForm7
  Left = 883
  Top = 283
  Width = 227
  Height = 354
  Caption = 'Parametrai'
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
  object GroupBox1: TGroupBox
    Left = 8
    Top = 0
    Width = 201
    Height = 89
    Caption = 'Ekranas'
    TabOrder = 0
    object Label1: TLabel
      Left = 144
      Top = 60
      Width = 6
      Height = 13
      Caption = 'h'
    end
    object RadioButton1: TRadioButton
      Left = 24
      Top = 24
      Width = 73
      Height = 17
      Caption = 'Tekstinis'
      TabOrder = 0
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 112
      Top = 24
      Width = 65
      Height = 17
      Caption = 'Grafinis'
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object LabeledEdit1: TLabeledEdit
      Left = 80
      Top = 56
      Width = 57
      Height = 21
      EditLabel.Width = 41
      EditLabel.Height = 13
      EditLabel.Caption = 'Adresas:'
      LabelPosition = lpLeft
      LabelSpacing = 3
      MaxLength = 5
      TabOrder = 2
      OnChange = LabeledEdit1Change
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 96
    Width = 201
    Height = 81
    Caption = 'Klaviat'#363'ra'
    TabOrder = 1
    object Label2: TLabel
      Left = 136
      Top = 20
      Width = 6
      Height = 13
      Caption = 'h'
    end
    object Label3: TLabel
      Left = 136
      Top = 52
      Width = 6
      Height = 13
      Caption = 'h'
    end
    object LabeledEdit2: TLabeledEdit
      Left = 80
      Top = 48
      Width = 49
      Height = 21
      EditLabel.Width = 64
      EditLabel.Height = 13
      EditLabel.Caption = 'Pertraukimas:'
      LabelPosition = lpLeft
      LabelSpacing = 3
      MaxLength = 2
      TabOrder = 0
      OnChange = LabeledEdit2Change
    end
    object LabeledEdit3: TLabeledEdit
      Left = 80
      Top = 16
      Width = 49
      Height = 21
      EditLabel.Width = 50
      EditLabel.Height = 13
      EditLabel.Caption = 'Prievadas:'
      LabelPosition = lpLeft
      LabelSpacing = 3
      MaxLength = 4
      TabOrder = 1
      OnChange = LabeledEdit3Change
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 184
    Width = 201
    Height = 105
    Caption = 'Emuliatorius'
    TabOrder = 2
    object Label4: TLabel
      Left = 24
      Top = 24
      Width = 76
      Height = 13
      Caption = 'Vykdymo greitis:'
    end
    object Label5: TLabel
      Left = 152
      Top = 72
      Width = 23
      Height = 13
      Caption = 'L'#279'tai'
    end
    object Label6: TLabel
      Left = 24
      Top = 72
      Width = 30
      Height = 13
      Caption = 'Greitai'
    end
    object TrackBar1: TTrackBar
      Left = 16
      Top = 40
      Width = 169
      Height = 33
      Orientation = trHorizontal
      Frequency = 2
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = TrackBar1Change
    end
  end
  object Button1: TButton
    Left = 8
    Top = 296
    Width = 75
    Height = 25
    Caption = 'At'#353'aukti'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 136
    Top = 296
    Width = 75
    Height = 25
    Caption = 'Keisti'
    TabOrder = 4
    OnClick = Button2Click
  end
end
