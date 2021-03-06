/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2015 - 2017 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#ifndef OTTER_QTWEBKITINSPECTOR_H
#define OTTER_QTWEBKITINSPECTOR_H

#include <QtWebKitWidgets/QWebInspector>
#ifdef OTTER_ENABLE_QTWEBKIT_LEGACY
#include <QtWidgets/QToolButton>
#endif

namespace Otter
{

class QtWebKitWebWidget;

class QtWebKitInspector final : public QWebInspector
{
	Q_OBJECT

public:
	explicit QtWebKitInspector(QtWebKitWebWidget *parent);

protected:
	void childEvent(QChildEvent *event) override;
#ifdef OTTER_ENABLE_QTWEBKIT_LEGACY
	void showEvent(QShowEvent *event) override;
	void resizeEvent(QResizeEvent *event) override;

protected slots:
	void hideInspector();

private:
	QtWebKitWebWidget *m_widget;
	QToolButton *m_closeButton;
#endif
};

}

#endif
