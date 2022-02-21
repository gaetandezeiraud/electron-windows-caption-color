'use strict';

const wcc = require('./build/Release/windowscaptioncolor.node');

module.exports = {
  SetCaptionColor: function(nativeWindowHandle, red, green, blue) {
    if(nativeWindowHandle == null)
			return -1;

    return wcc.SetCaptionColor(nativeWindowHandle, red, green, blue);
  }
};
