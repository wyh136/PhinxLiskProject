object frmSpeedTest: TfrmSpeedTest
  Left = 0
  Top = 0
  Caption = 'Public Node Speed Testing'
  ClientHeight = 313
  ClientWidth = 553
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
  object GroupBox2: TGroupBox
    Left = 0
    Top = 208
    Width = 553
    Height = 105
    Align = alBottom
    TabOrder = 0
    ExplicitLeft = 8
    ExplicitTop = 159
    ExplicitWidth = 554
    DesignSize = (
      553
      105)
    object Button1: TButton
      Left = 476
      Top = 9
      Width = 74
      Height = 42
      Anchors = [akTop, akRight]
      Caption = 'Test'
      Enabled = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 476
      Top = 55
      Width = 75
      Height = 42
      Anchors = [akTop, akRight]
      Caption = 'Quit'
      TabOrder = 1
      OnClick = Button2Click
    end
    object Memo1: TMemo
      Left = 10
      Top = 9
      Width = 460
      Height = 88
      Align = alCustom
      Anchors = [akLeft, akTop, akRight, akBottom]
      ReadOnly = True
      ScrollBars = ssVertical
      TabOrder = 2
    end
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 553
    Height = 208
    Align = alClient
    Caption = ' Public Nodes '
    TabOrder = 1
    ExplicitLeft = 8
    ExplicitTop = 8
    ExplicitWidth = 537
    ExplicitHeight = 145
    object lv: TListView
      Left = 2
      Top = 15
      Width = 549
      Height = 191
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
      DoubleBuffered = True
      GridLines = True
      ReadOnly = True
      RowSelect = True
      ParentDoubleBuffered = False
      SortType = stData
      TabOrder = 0
      ViewStyle = vsReport
      ExplicitWidth = 533
      ExplicitHeight = 128
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 5
    OnTimer = Timer1Timer
    Left = 400
    Top = 111
  end
end
