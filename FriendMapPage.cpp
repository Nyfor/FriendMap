/*!
 * @file FriendMapPage.cpp
 * @author RetroShare Team
 *
 * Copyright (C) 2014 - RetroShare Team
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

#include "FriendMapPage.h"
#include "ui_FriendMapPage.h"


//!
//! \brief FriendMapPage::FriendMapPage
//! \param peers
//!
FriendMapPage::FriendMapPage() :
    ui(new Ui::FriendMapPage)
{
    ui->setupUi(this);
    //this->setWindowTitle(QString("FriendMap"));
    ui->MarbleWidget->setShowCompass(false);
    ui->MarbleWidget->setShowCrosshairs(false);
    this->layer = NULL;
    this->data_model = NULL;
}

//!
//! \brief FriendMapPage::~FriendMapPage
//! Destructor which destroys the user interace
//!
FriendMapPage::~FriendMapPage()
{
    if(layer){
        ui->MarbleWidget->removeLayer(layer);
        delete layer;
    }
    delete ui;
}

//!
//! \brief FriendMapPage::setConfig
//! \param settings
//!
void FriendMapPage::setConfig(FriendMapSettings* settings){
    this->settings = settings;
    ui->MarbleWidget->setMapThemeId(settings->getMapThemeId().c_str());
    ui->MarbleWidget->setProjection(settings->getProjection());
    ui->MarbleWidget->setShowGrid(settings->getShowGrid());

    ui->MarbleWidget->setShowBorders(settings->getShowBorders());
    ui->MarbleWidget->setShowCities(settings->getShowCities());
    ui->MarbleWidget->setShowIceLayer(settings->getShowIceLayer());
    ui->MarbleWidget->setShowClouds(settings->getShowClouds());
    ui->MarbleWidget->setShowCityLights(settings->getShowCityLights());
    ui->MarbleWidget->setShowSunShading(settings->getShowSunShading());
    if(settings->validPaths()){
        interface::setSetting(*settings);
        if(!data_model)
            data_model = new DataModel(ui->MarbleWidget->model()->treeModel());
        if(layer == NULL){
            layer = new PaintLayer(settings, data_model);
        }
        layer->setSettings(*settings);
        //connect(ui->MarbleWidget, SIGNAL(mouseClickGeoPosition(qreal,qreal,GeoDataCoordinates::Unit)), layer, SLOT(genPeerCache());//enable to update cache on click
        ui->MarbleWidget->addLayer(layer);
    } else {
        QMessageBox::information(this,
                                 tr("FriendMap"),
                                 QString(tr("GeoIP Data not found!")));
    }
}

// eof   
