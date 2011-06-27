qx.Class.define("gtmweb.MainWindow",
{
  extend : qx.ui.window.Window,

  construct : function()
  {
    this.base(arguments, "GTM - Webinterface - www.greentomatomod.com"),
    this.setShowMinimize(false);
    this.setWidth(750);
    this.setHeight(650);
  }
});