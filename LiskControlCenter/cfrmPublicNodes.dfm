object frmPublicNodes: TfrmPublicNodes
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsToolWindow
  Caption = 'Public Nodes Editor'
  ClientHeight = 432
  ClientWidth = 318
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  Padding.Left = 5
  Padding.Top = 5
  Padding.Right = 5
  Padding.Bottom = 5
  OldCreateOrder = False
  Position = poDefault
  ScreenSnap = True
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 5
    Top = 5
    Width = 308
    Height = 422
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 13
    ExplicitTop = 13
    ExplicitWidth = 292
    ExplicitHeight = 356
    object TabSheet1: TTabSheet
      Caption = 'MainNet'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 571
      ExplicitHeight = 266
      object lvMain: TListView
        Left = 0
        Top = 0
        Width = 300
        Height = 266
        Align = alClient
        Columns = <
          item
            Caption = '#'
          end
          item
            Alignment = taCenter
            Caption = 'Owner'
            Width = 100
          end
          item
            AutoSize = True
            Caption = 'URL'
          end>
        FlatScrollBars = True
        GridLines = True
        ReadOnly = True
        RowSelect = True
        TabOrder = 0
        ViewStyle = vsReport
        OnSelectItem = lvMainSelectItem
        ExplicitWidth = 284
        ExplicitHeight = 169
      end
      object GroupBox1: TGroupBox
        Left = 0
        Top = 266
        Width = 300
        Height = 128
        Align = alBottom
        Caption = ' Edit '
        TabOrder = 1
        ExplicitTop = 200
        ExplicitWidth = 284
        object Label1: TLabel
          Left = 16
          Top = 32
          Width = 39
          Height = 13
          Caption = 'Owner :'
        end
        object Label2: TLabel
          Left = 16
          Top = 64
          Width = 29
          Height = 13
          Caption = 'URL : '
        end
        object edt_owner: TEdit
          Left = 61
          Top = 29
          Width = 207
          Height = 21
          TabOrder = 0
        end
        object edt_url: TEdit
          Left = 61
          Top = 61
          Width = 207
          Height = 21
          TabOrder = 1
        end
        object bt_new: TButton
          Left = 35
          Top = 94
          Width = 47
          Height = 25
          Caption = 'Add'
          TabOrder = 2
          OnClick = bt_newClick
        end
        object bt_del: TButton
          Left = 88
          Top = 94
          Width = 47
          Height = 25
          Caption = 'Del'
          TabOrder = 3
          OnClick = bt_delClick
        end
        object bt_save: TButton
          Left = 141
          Top = 94
          Width = 47
          Height = 25
          Caption = 'Save'
          TabOrder = 4
          OnClick = bt_saveClick
        end
        object bt_Cancel: TButton
          Left = 194
          Top = 94
          Width = 47
          Height = 25
          Caption = 'Cancel'
          TabOrder = 5
          OnClick = bt_CancelClick
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'TestNet'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 571
      ExplicitHeight = 266
      object lvTest: TListView
        Left = 0
        Top = 0
        Width = 300
        Height = 266
        Align = alClient
        Columns = <
          item
            Caption = '#'
          end
          item
            Alignment = taCenter
            Caption = 'Owner'
            Width = 100
          end
          item
            AutoSize = True
            Caption = 'URL'
          end>
        GridLines = True
        ReadOnly = True
        RowSelect = True
        TabOrder = 0
        ViewStyle = vsReport
        OnSelectItem = lvTestSelectItem
        ExplicitWidth = 290
        ExplicitHeight = 265
      end
      object GroupBox2: TGroupBox
        Left = 0
        Top = 266
        Width = 300
        Height = 128
        Align = alBottom
        Caption = ' Edit '
        TabOrder = 1
        ExplicitTop = 200
        ExplicitWidth = 284
        object Label3: TLabel
          Left = 16
          Top = 32
          Width = 39
          Height = 13
          Caption = 'Owner :'
        end
        object Label4: TLabel
          Left = 16
          Top = 64
          Width = 29
          Height = 13
          Caption = 'URL : '
        end
        object Edit1: TEdit
          Left = 61
          Top = 29
          Width = 207
          Height = 21
          TabOrder = 0
        end
        object Edit2: TEdit
          Left = 61
          Top = 61
          Width = 207
          Height = 21
          TabOrder = 1
        end
        object Button1: TButton
          Left = 35
          Top = 94
          Width = 47
          Height = 25
          Caption = 'Add'
          TabOrder = 2
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 88
          Top = 94
          Width = 47
          Height = 25
          Caption = 'Del'
          TabOrder = 3
          OnClick = Button2Click
        end
        object Button3: TButton
          Left = 141
          Top = 94
          Width = 47
          Height = 25
          Caption = 'Save'
          TabOrder = 4
          OnClick = Button3Click
        end
        object Button4: TButton
          Left = 194
          Top = 94
          Width = 47
          Height = 25
          Caption = 'Cancel'
          TabOrder = 5
          OnClick = Button4Click
        end
      end
    end
  end
end
