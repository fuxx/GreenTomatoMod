qx.Class.define("gtmweb.TableCellEditor",
{
  extend : qx.core.Object,
  implement : qx.ui.table.ICellEditorFactory,

  members :
  {
    // overridden
    createCellEditor : function(cellInfo)
    {
      // Create the cell editor window, since we need to return it
      // immediately.
      var cellEditor = new qx.ui.window.Window("Edit");
      cellEditor.setLayout(new qx.ui.layout.HBox(4));
      cellEditor.set(
      {
        padding: 3,
        modal: true,
        showClose: false,
        showMaximize: false,
        showMinimize: false
      });
      cellEditor.moveTo(300, 250);
      cellEditor.setMinWidth(500);


      cellEditor.addListener("appear", function(e)
      {
        cellEditor.__cellEditor.focus();
        cellEditor.__cellEditor.setTextSelection(0, cellEditor.__cellEditor.getValue().length);
      });


      // Create a text field in which to edit the data
      cellEditor.__cellEditor = new qx.ui.form.TextField(cellInfo.value + "").set({
        allowGrowY: true,
        width: 400
      });
      cellEditor.add(cellEditor.__cellEditor);

      // Create the "Save" button to close the cell editor
      var save = new qx.ui.form.Button("Save");
      save.addListener("execute", function(e) {
        cellEditor.close();
      });
      cellEditor.add(save);

      // Let them press Enter from the cell editor text field to finish.
      var command = new qx.ui.core.Command("Enter");
      command.addListener("execute", function(e)
      {
        save.execute();
        command.dispose();
        command = null;
      });

      return cellEditor;
    },

    // overridden
    getCellEditorValue : function(cellEditor)
    {
      // Return the value in the text field
      return parseFloat(cellEditor.__cellEditor.getValue());
    }
  }
});