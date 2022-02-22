'use strict';

const wcc = require('./build/Release/windowscaptioncolor.node');

module.exports = {
  SetCaptionColor: function(browserWindow, red, green, blue) {
    try {
      return wcc.SetCaptionColor(browserWindow.getNativeWindowHandle(), red, green, blue);
    } catch (e) {
      throw new TypeError('NOT_VALID_WINDOW')
    }
  }
};
