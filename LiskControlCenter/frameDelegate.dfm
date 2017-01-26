object framDelegate: TframDelegate
  Left = 0
  Top = 0
  Width = 781
  Height = 141
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Microsoft YaHei UI'
  Font.Style = []
  ParentFont = False
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 384
    Height = 141
    Align = alClient
    Caption = ' Delegater Infomation '
    TabOrder = 0
    ExplicitWidth = 397
    ExplicitHeight = 153
    object Label3: TLabel
      Left = 66
      Top = 108
      Width = 58
      Height = 19
      Caption = 'Balance : '
    end
    object Label2: TLabel
      Left = 41
      Top = 67
      Width = 83
      Height = 19
      Caption = 'LSK Address :'
      FocusControl = ed_address
    end
    object Label1: TLabel
      Left = 24
      Top = 32
      Width = 100
      Height = 19
      Caption = 'DelegateNAme :'
    end
    object lb_name: TLabel
      Left = 144
      Top = 32
      Width = 22
      Height = 19
      Caption = ' -/-'
    end
    object lb_rank: TLabel
      Left = 327
      Top = 32
      Width = 44
      Height = 19
      Caption = 'lb_rank'
    end
    object lb_balance: TLabel
      Left = 144
      Top = 106
      Width = 54
      Height = 21
      Caption = '0.0 LSK'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clYellow
      Font.Height = -16
      Font.Name = 'Microsoft YaHei UI'
      Font.Style = []
      ParentFont = False
    end
    object ed_address: TEdit
      Left = 144
      Top = 64
      Width = 223
      Height = 27
      ReadOnly = True
      TabOrder = 0
    end
  end
  object Panel1: TPanel
    Left = 384
    Top = 0
    Width = 397
    Height = 141
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 1
    ExplicitLeft = 0
    ExplicitTop = 159
    ExplicitHeight = 138
    object GroupBox2: TGroupBox
      Left = 0
      Top = 0
      Width = 124
      Height = 141
      Align = alLeft
      Caption = ' Votes '
      TabOrder = 0
      ExplicitLeft = 337
      ExplicitHeight = 136
      object lb_votes: TLabel
        Left = 3
        Top = 40
        Width = 115
        Height = 19
        Alignment = taCenter
        AutoSize = False
        Caption = '0 votes'
      end
      object lb_appr: TLabel
        Left = 3
        Top = 80
        Width = 115
        Height = 31
        Alignment = taCenter
        AutoSize = False
        Caption = '0 %'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -24
        Font.Name = 'Microsoft YaHei UI'
        Font.Style = []
        ParentFont = False
      end
    end
    object GroupBox3: TGroupBox
      Left = 124
      Top = 0
      Width = 273
      Height = 141
      Align = alClient
      Caption = ' Productivity '
      TabOrder = 1
      ExplicitLeft = 309
      ExplicitWidth = 271
      ExplicitHeight = 136
      object label11: TLabel
        Left = 19
        Top = 32
        Width = 93
        Height = 19
        Caption = 'Forged Blocks :'
      end
      object lb_pblocks: TLabel
        Left = 128
        Top = 32
        Width = 8
        Height = 19
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clHotLight
        Font.Height = -13
        Font.Name = 'Microsoft YaHei UI'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 19
        Top = 56
        Width = 93
        Height = 19
        Caption = 'Missed Blocks :'
      end
      object lb_missed: TLabel
        Left = 128
        Top = 56
        Width = 8
        Height = 19
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -13
        Font.Name = 'Microsoft YaHei UI'
        Font.Style = []
        ParentFont = False
      end
      object lb_pos: TLabel
        Left = 19
        Top = 111
        Width = 39
        Height = 19
        Caption = 'lb_pos'
      end
      object pbar: TProgressBar
        Left = 19
        Top = 81
        Width = 230
        Height = 24
        Position = 30
        Smooth = True
        TabOrder = 0
      end
    end
  end
end
