/* ************************************************************************

   Copyright:

   License:

   Authors:

************************************************************************ */

/* ************************************************************************

#asset(gtmweb/*)

************************************************************************ */

/**
 * This is the main application class of your custom application "gtmweb"
 */
qx.Class.define("gtmweb.Application",
{
  extend : qx.application.Standalone,



  /*
  *****************************************************************************
     MEMBERS
  *****************************************************************************
  */

  members :
  {
    /**
     * This method contains the initial application code and gets called 
     * during startup of the application
     * 
     * @lint ignoreDeprecated(alert)
     */
    main : function()
    {
      // check for login and cookie!
      /*var loggedin = qx.bom.Cookie.get("LOG");
      var sessionid = qx.bom.Cookie.get("MDID");
      if (loggedin == null || sessionid == null) {
        var login = new gtmweb.LoginWindow();
        login.main();
        return 0;
      }*/
      // Call super class
      this.base(arguments);

      // Enable logging in debug variant
      if (qx.core.Variant.isSet("qx.debug", "on"))
      {
        // support native logging capabilities, e.g. Firebug for Firefox
        qx.log.appender.Native;
        // support additional cross-browser console. Press F7 to toggle visibility
        qx.log.appender.Console;
      }
      
      // views
      var statusWin = new gtmweb.StatusWindow();
      var messagesWin = new gtmweb.MessagesWindow();
      
      // Document is the application root
      var doc = this.getRoot();
      // create the tree
      var tree = new qx.ui.tree.Tree();
      tree.set({
        width: 160,
        height: 650
      });
      
      /**
       * Menu
       */
      this.getRoot().add(new qx.ui.basic.Image("resource/gtmweb/logo-webinterface.png"), {left: 25, top: 700});
      this.getRoot().add(tree, {left: 25, top: 50});
      var root = new qx.ui.tree.TreeFile("Server");
      root.setIcon("resource/gtmweb/icon/22/network-workgroup.png");
      root.addListener("click", function(e) {
        statusWin.getOverview(this, mainWindow);
      });
      
      root.addListener("dblclick", function(e) {
        statusWin.getOverview(this, mainWindow);
      });
      
      
      var status = new qx.ui.tree.TreeFile("Server status");
      status.setIcon("resource/gtmweb/icon/22/computer.png");
      root.add(status);
      var settings = new qx.ui.tree.TreeFolder("GTM Settings");
      settings.setIcon("resource/gtmweb/icon/22/engineering.png");
      root.add(settings);
      // base menu
      var bMain = new qx.ui.tree.TreeFile("Main");
      bMain.setIcon("");
      settings.add(bMain);
      
      var bMessages = new qx.ui.tree.TreeFile("Messages");
      bMessages.setIcon("");
      settings.add(bMessages);
      bMessages.addListener("click", function(e) {
        messagesWin.getOverview(this, mainWindow);
      });
      
      root.addListener("dblclick", function(e) {
        statusWin.getOverview(this, mainWindow);
      });
      
      /*var bPmSettings = new qx.ui.tree.TreeFile("PM Settings");
      bPmSettings.setIcon("");
      settings.add(bPmSettings);*/
      
      var bRanking = new qx.ui.tree.TreeFile("Ranking");
      bRanking.setIcon("");
      settings.add(bRanking);
      
      
      
      // weapon menu
      var menuWeapon = new qx.ui.tree.TreeFolder("Weapons");
      menuWeapon.setIcon("resource/gtmweb/icon/22/weapon.gif");
      root.add(menuWeapon);
      var wRestrictions = new qx.ui.tree.TreeFile("Restrictions");
      wRestrictions.setIcon("");
      menuWeapon.add(wRestrictions);
      
      // stats menu
      var menuStats = new qx.ui.tree.TreeFolder("Stats/Info");
      menuStats.setIcon("resource/gtmweb/icon/22/logviewer.png");
      root.add(menuStats);
      var sInfo = new qx.ui.tree.TreeFile("Info");
      sInfo.setIcon("");
      menuStats.add(sInfo);
      var sStats = new qx.ui.tree.TreeFile("Statistics");
      sStats.setIcon("");
      menuStats.add(sStats);
      
      // logout menu
      var logOut = new qx.ui.tree.TreeFile("Logout");
      logOut.setIcon("resource/gtmweb/icon/22/utilities-keyring.png");
      root.add(logOut);
      
      tree.setRoot(root);
      root.setOpen(true);
      settings.setOpen(true);
      menuWeapon.setOpen(true);
      menuStats.setOpen(true);
      tree.setSelection([root]);
      
      /**
       * Main window
       */
      var mainWindow = new gtmweb.MainWindow();
      mainWindow.setAllowClose(false);
      this.getRoot().add(mainWindow, {left:190, top:50});
      var layout = new qx.ui.layout.VBox();
      layout.setSeparator("separator-vertical");
      mainWindow.setLayout(layout);
      mainWindow.setShowMinimize(false);
      mainWindow.setAllowClose(false);
      mainWindow.setContentPadding(10);
      mainWindow.setLayout(layout); 
      mainWindow.open();
      
      // we call the serverinfo here at the end, that the window shows something ;)
      statusWin.getOverview(this, mainWindow);
      
    }
  }
});
