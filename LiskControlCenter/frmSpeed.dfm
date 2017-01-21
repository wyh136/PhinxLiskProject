object frmSpeedTest: TfrmSpeedTest
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Public Node Speed Testing'
  ClientHeight = 263
  ClientWidth = 554
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poMainFormCenter
  ScreenSnap = True
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 537
    Height = 145
    Caption = ' Public Nodes '
    TabOrder = 0
    object lv: TListView
      Left = 2
      Top = 15
      Width = 533
      Height = 128
      Align = alClient
      Columns = <
        item
          Caption = '#'
        end
        item
          Caption = 'Owner'
          Width = 100
        end
        item
          Caption = 'URL'
          Width = 180
        end
        item
          Caption = 'NetWork'
          Width = 80
        end
        item
          AutoSize = True
          Caption = 'Speed ( ms )'
        end>
      GridLines = True
      ReadOnly = True
      RowSelect = True
      SortType = stData
      TabOrder = 0
      ViewStyle = vsReport
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 159
    Width = 457
    Height = 96
    TabOrder = 1
    object Memo1: TMemo
      Left = 2
      Top = 15
      Width = 453
      Height = 79
      Align = alClient
      ReadOnly = True
      ScrollBars = ssVertical
      TabOrder = 0
      ExplicitWidth = 455
    end
  end
  object Button1: TButton
    Left = 469
    Top = 159
    Width = 75
    Height = 42
    Caption = 'Test'
    Enabled = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 469
    Top = 207
    Width = 75
    Height = 42
    Caption = 'Quit'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 5
    OnTimer = Timer1Timer
    Left = 400
    Top = 111
  end
end
