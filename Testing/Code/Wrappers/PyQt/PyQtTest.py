# -*- coding: utf-8 -*-

import sys
import otbApplication as otb_core
import otbapp as otb_gui
from PyQt4 import QtGui, QtCore


if __name__ == "__main__":
    qapp = QtGui.QApplication(sys.argv)

    app = otb_core.Registry.CreateApplication(sys.argv[1])

    widget = otb_gui.QParameterView(app)
    widget.CreateGui()
    widget.show()

    QtCore.QTimer.singleShot(1000, qapp, QtCore.SLOT('closeAllWindows()'))
    sys.exit(qapp.exec_())

