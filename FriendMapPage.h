/*!
 * @file FriendMapPage.h
 * @author Nyfor, RetroShare Team
 * 
 * Copyright (C) 2014 - Nyfor, RetroShare Team
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */

#ifndef FRIENDMAPPAGE_H
#define FRIENDMAPPAGE_H

#include <marble/MarbleModel.h>
#include <retroshare-gui/mainpage.h>
#include <retroshare/rsplugin.h>
#include <QMessageBox>
#include <QTimer>
#include <QWidget>
#include "FriendMapSettings.h"
#include "PaintLayer.h"

namespace Ui {
class FriendMapPage;
}

class FriendMapPage : public MainPage {
    Q_OBJECT

   public:
    FriendMapPage();
    void setConfig(FriendMapSettings* settings);
    ~FriendMapPage();

   private:
    QSharedPointer<Ui::FriendMapPage> ui;
    PaintLayer* layer;
    DataModel* data_model;
    FriendMapSettings* settings;
};

#endif  // FRIENDMAPPAGE_H
