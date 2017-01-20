object frmDlgdashbrd: TfrmDlgdashbrd
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Delegater DashBoard'
  ClientHeight = 615
  ClientWidth = 806
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  Padding.Left = 10
  Padding.Top = 10
  Padding.Right = 10
  Padding.Bottom = 10
  OldCreateOrder = False
  Position = poMainFormCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 10
    Top = 10
    Width = 786
    Height = 153
    Align = alTop
    Caption = 'Panel1'
    TabOrder = 0
  end
  object Panel2: TPanel
    Left = 10
    Top = 163
    Width = 786
    Height = 144
    Align = alTop
    Caption = 'Panel1'
    TabOrder = 1
    ExplicitLeft = 7
    ExplicitTop = 158
  end
  object Panel3: TPanel
    Left = 10
    Top = 307
    Width = 786
    Height = 298
    Align = alClient
    TabOrder = 2
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 393
      Height = 296
      Align = alLeft
      Alignment = taLeftJustify
      TabOrder = 0
    end
    object Panel5: TPanel
      Left = 394
      Top = 1
      Width = 391
      Height = 296
      Align = alClient
      Alignment = taLeftJustify
      TabOrder = 1
    end
  end
end
