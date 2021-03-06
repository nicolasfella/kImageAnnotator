/*
 * Copyright (C) 2020 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef ANNOTATIONTABWIDGET_H
#define ANNOTATIONTABWIDGET_H

#include <QTabWidget>
#include <QPixmap>

#include "AnnotationTabContent.h"

namespace kImageAnnotator {

class AnnotationTabWidget : public QTabWidget
{
	Q_OBJECT
public:
	AnnotationTabWidget(Config *config, AbstractSettingsProvider *settingsProvider);
	~AnnotationTabWidget() override = default;
	int addImage(const QPixmap &image, const QString &title, const QString &toolTip);
	AnnotationArea* currentAnnotationArea() const;
	QAction* undoAction() const;
	QAction* redoAction() const;
	void updateTabInfo(int index, const QString &title, const QString &toolTip);

signals:
	void imageChanged() const;
	void tabMoved(int fromIndex, int toIndex) const;

protected:
	void tabInserted(int index) override;
	void tabRemoved(int index) override;

private:
	Config *mConfig;
	AbstractSettingsProvider *mSettingsProvider;
	QAction *mUndoAction;
	QAction *mRedoAction;

private slots:
	void undoTriggered();
	void redoTriggered();
	void updateTabsClosable();
	void updateCurrentWidget(int index);
};

} // namespace kImageAnnotator

#endif //ANNOTATIONTABWIDGET_H
