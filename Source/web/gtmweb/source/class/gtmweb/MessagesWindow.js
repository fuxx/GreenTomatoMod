qx.Class.define("gtmweb.MessagesWindow",
{
  extend : qx.ui.window.Window,

  construct : function()
  {
    this.base(arguments, "Server messages"),
    this.setShowMinimize(false);
    this.setWidth(700);
    this.setHeight(600);
  },
  
  members : {
    getOverview: function(parentWindow, mainWindow) {
        
      mainWindow.removeAll();
      
      /* GroupBox Design */
      var GridGroupBox = new qx.ui.groupbox.GroupBox("Server messages");
      var layout = new qx.ui.layout.VBox();
      GridGroupBox.setLayout(layout);
      var root = new qx.ui.container.Composite(new qx.ui.layout.VBox(20)).set({
          padding: 10
      })
        
      root.add(GridGroupBox);
      mainWindow.add(root);
      
      /***
       * MESSAGES TABLE
       */
      // table model
      var bar = new qx.ui.toolbar.ToolBar();
      var part = new qx.ui.toolbar.Part();
      bar.add(part);
      
      var tableModel = this._tableModel = new qx.ui.table.model.Simple();
      tableModel.setColumns([ "ID", "Message", "Show message" ]);
      tableModel.setColumnEditable(0, false);
      tableModel.setColumnEditable(1, true);
      tableModel.setColumnEditable(2, true);


      // table
      var table = new qx.ui.table.Table(tableModel);
      table.getSelectionModel().setSelectionMode(qx.ui.table.selection.Model.SINGLE_SELECTION);
      /*table.addListener("cellClick",
        function(cellEvent) {           
             if (cellEvent.getColumn() == 2) {
                var oldValue = table.getTableModel().getValue(cellEvent.getColumn(), cellEvent.getRow());
                oldValue = !oldValue;
                var renderer = table.getTableColumnModel().getDataCellRenderer(ellEvent.getColumn());
                table.getTableModel().setValue(cellEvent.getColumn(), cellEvent.getRow(), oldValue);
              }
         });*/
      
      var tcm = table.getTableColumnModel();
      var bool = new qx.ui.table.cellrenderer.Boolean();
      tcm.setDataCellRenderer(2, bool);
      tcm.setCellEditorFactory(2,new qx.ui.table.celleditor.CheckBox());
      
      tcm.setColumnWidth(1, 500)
      tcm.setColumnVisible(0, false);
      tcm.setCellEditorFactory(1, new gtmweb.TableCellEditor());
    
      GridGroupBox.add(bar);
      GridGroupBox.add(table);
      
      // Create the initial data
      var tableData = [[1,'Welcome to the real world! We just dont like you ;)', true], [2,'Iam another useless message until ajax backend works =/', false]];
      this._tableModel.addRows(tableData);
      
      button = new qx.ui.toolbar.Button("Add message", "resource/gtmweb/icon/22/list-add.png");
      button.addListener("execute", function(evt) {
        var rowData = [666,['Double click me', 0]];
        this._tableModel.addRows(rowData);
      }, this);
      part.add(button);

      var button = new qx.ui.toolbar.Button("Remove selected message", "resource/gtmweb/icon/22/list-remove.png");
      button.addListener("execute", function(evt) {
        if (!table.getSelectionModel().isSelectionEmpty()) {
          
          var selection = [];
          table.getSelectionModel().iterateSelection(function(ind) {
            table.getTableModel().removeRows(ind, 1);
        });
        }
      }, this);
      part.add(button);
      
      /***
       * RULES TABLE
       */
      // table model
      var bar = new qx.ui.toolbar.ToolBar();
      var part = new qx.ui.toolbar.Part();
      bar.add(part);
      
      var tableModel = this._tableModel = new qx.ui.table.model.Simple();
      tableModel.setColumns([ "ID", "Message", "Show message" ]);
      tableModel.setColumnEditable(0, false);
      
      // table
      var table = new qx.ui.table.Table(tableModel);
      table.getSelectionModel().setSelectionMode(qx.ui.table.selection.Model.SINGLE_SELECTION);
      
      var tcm = table.getTableColumnModel();
      tcm.setColumnWidth(1, 500)
      tcm.setColumnVisible(0, false);
      tcm.setCellEditorFactory(1, new gtmweb.TableCellEditor());
      
      tcm.setDataCellRenderer(2, new qx.ui.table.cellrenderer.Boolean());
      tcm.setCellEditorFactory(2,new qx.ui.table.celleditor.CheckBox());
      
      GridGroupBox.add(bar);
      GridGroupBox.add(table);
      
      // Create the initial data
      var tableData = [[1,'Welcome to the real world! We just dont like you ;)', true], [2,'Iam another useless message until ajax backend works =/', false]];
      this._tableModel.addRows(tableData);
      
      button = new qx.ui.toolbar.Button("Add message", "resource/gtmweb/icon/22/list-add.png");
      button.addListener("execute", function(evt) {
        var rowData = [666,['Double click me', 0]];
        this._tableModel.addRows(rowData);
      }, this);
      part.add(button);

      var button = new qx.ui.toolbar.Button("Remove selected message", "resource/gtmweb/icon/22/list-remove.png");
      button.addListener("execute", function(evt) {
        if (!table.getSelectionModel().isSelectionEmpty()) {
          
          var selection = [];
          table.getSelectionModel().iterateSelection(function(ind) {
            table.getTableModel().removeRows(ind, 1);
        });
        }
      }, this);
      part.add(button);
      
    }
  }
});