object frmVotes: TfrmVotes
  Left = 0
  Top = 0
  Caption = 'Votes Manager'
  ClientHeight = 414
  ClientWidth = 785
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object lv: TListView
    Left = 0
    Top = 0
    Width = 785
    Height = 414
    Align = alClient
    Columns = <
      item
        Caption = '#'
      end
      item
        Caption = 'Voter Name'
        Width = 150
      end
      item
        Caption = 'Address'
        Width = 200
      end
      item
        AutoSize = True
        Caption = 'Balance'
      end
      item
        AutoSize = True
        Caption = 'Sum.'
      end>
    GridLines = True
    TabOrder = 0
    ViewStyle = vsReport
  end
end
