qx.Class.define("gtmweb.StatusWindow",
{
  extend : qx.ui.window.Window,

  construct : function()
  {
    this.base(arguments, "Server overview"),
    this.setShowMinimize(false);
    this.setWidth(700);
    this.setHeight(600);
  },
  
  members : {
    getOverview: function(parentWindow, mainWindow) {
        
        mainWindow.removeAll();
        var textGroupBox = new qx.ui.groupbox.GroupBox("Configuration file");
        var layout = new qx.ui.layout.VBox();
        textGroupBox.setLayout(layout);
        
        var root = new qx.ui.container.Composite(new qx.ui.layout.VBox(20)).set({
            padding: 10
        })
        
        root.add(textGroupBox);
        mainWindow.add(root);
  
        // text field
        var serverName = new qx.ui.form.TextField();
        serverName.setPlaceholder("Servername from configfile");
        serverName.setValue("SniperOnly 24/7")
        var label = new qx.ui.basic.Label("Servername:");
        label.setBuddy(serverName);
        textGroupBox.add(label);
        textGroupBox.add(serverName);
        
        // text field
        var ipAddress = new qx.ui.form.TextField();
        ipAddress.setPlaceholder("127.0.0.1");
        ipAddress.setValue("127.0.0.1")
        var label = new qx.ui.basic.Label("IP-Address:");
        label.setPaddingTop(10);
        label.setBuddy(ipAddress);
        textGroupBox.add(label);
        textGroupBox.add(ipAddress);
        
        // text field
        var logUrl = new qx.ui.form.TextArea("text\narea\nnowrap");
        logUrl.setPlaceholder("This should show your log-url");
        logUrl.setValue("http://logs.gameservers.com/195.122.134.189:3124/0b69cfae-cb06-46ee-a9d7-63414f547250");
        var label = new qx.ui.basic.Label("Log-URL:");
        label.setPaddingTop(10);
        label.setBuddy(logUrl);
        textGroupBox.add(label);
        textGroupBox.add(logUrl);
        
      }
    }
});