object ffrmServers: TffrmServers
  Left = 0
  Top = 0
  Width = 718
  Height = 188
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Microsoft YaHei UI'
  Font.Style = []
  ParentFont = False
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 718
    Height = 188
    Align = alClient
    Caption = 'Server Array [ - ]'
    TabOrder = 0
    object lv: TListView
      Left = 2
      Top = 23
      Width = 714
      Height = 163
      Align = alClient
      Checkboxes = True
      Columns = <
        item
          Caption = '#'
        end
        item
          AutoSize = True
          Caption = 'Server URL'
        end
        item
          Caption = 'Height'
          Width = 90
        end
        item
          Caption = 'BroadHash'
          Width = 200
        end
        item
          Caption = 'Consensus '
          Width = 100
        end
        item
          Caption = 'State'
          Width = 90
        end>
      FlatScrollBars = True
      GridLines = True
      ReadOnly = True
      RowSelect = True
      TabOrder = 0
      ViewStyle = vsReport
    end
  end
end
