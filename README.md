![NpmLicense](https://img.shields.io/npm/l/express.svg)

> 🟡 **Project status**: maintenance mode
  - Project is no longer in active development
  - Only bug-related issues are accepted
  - Only bug-related pull requests are accepted
  - New features are unlikely to be added
  - Project status may eventually transition to "discontinued" or back to "active"

# Electron Windows Caption Color
> Change the color of the title bar (caption) of a win32 electronJS application. Windows 11 Only.

<br>
<hr>
<p align="center">
If you find this package useful, please don't forget to star ⭐️ the repo, as this will help to promote the project.<br>
</p>
<hr>


## Installation

Install as a dependency for your project (need python 3.x):

```bash
npm i electron-windows-caption-color
```

## Usage

```javascript
const electronCustomCaption = require('electron-windows-caption-color');
electronCustomCaption.SetCaptionColor(mainWindow, 255, 0, 0); // Red
```
