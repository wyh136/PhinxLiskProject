object MainFrm: TMainFrm
  Left = 0
  Top = 0
  Caption = 'MainFrm'
  ClientHeight = 693
  ClientWidth = 1152
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = MM
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object sbar: TStatusBar
    Left = 0
    Top = 674
    Width = 1152
    Height = 19
    Panels = <
      item
        Width = 80
      end
      item
        Width = 200
      end
      item
        Width = 130
      end
      item
        Width = 180
      end
      item
        Width = 130
      end
      item
        Width = 200
      end
      item
        Width = 50
      end>
    ExplicitTop = 528
    ExplicitWidth = 1083
  end
  object MM: TMainMenu
    Left = 280
    Top = 176
    object mm_network: TMenuItem
      Caption = '&Network'
      object mn_pubnodes: TMenuItem
        Caption = '&Public Nodes ...'
        OnClick = mn_pubnodesClick
      end
      object nm_LiskExplorers: TMenuItem
        Caption = 'Lisk &Explorers ...'
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object DisplayTestNet1: TMenuItem
        Caption = 'Display &Testnet'
        Checked = True
      end
    end
    object DelegaterTools1: TMenuItem
      Caption = '&Delegater Tools'
      object ForgingDashboard1: TMenuItem
        Caption = '&Forging Dashboard ...'
        OnClick = ForgingDashboard1Click
      end
      object VotesManager1: TMenuItem
        Caption = '&Votes Manager ...'
      end
      object ReportGenerator1: TMenuItem
        Caption = '&Report Generator ...'
      end
    end
    object Wallet1: TMenuItem
      Caption = '&Wallet'
      object OpenWallet1: TMenuItem
        Caption = '&Send Transaction ...'
      end
      object MultiSignature1: TMenuItem
        Caption = '&MultiSignature ...'
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object AddressBook1: TMenuItem
        Caption = 'Address &Book ...'
      end
    end
  end
end
