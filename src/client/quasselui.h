/***************************************************************************
 *   Copyright (C) 2005-08 by the Quassel Project                          *
 *   devel@quassel-irc.org                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) version 3.                                           *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _QUASSELUI_H_
#define _QUASSELUI_H_

#include <QObject>
#include "message.h"

class MessageModel;

class AbstractUiMsg {

  public:
    virtual ~AbstractUiMsg() {};
    virtual QString sender() const = 0;
    virtual QString text() const = 0;
    virtual MsgId msgId() const = 0;
    virtual BufferInfo bufferInfo() const = 0;
    virtual QDateTime timestamp() const = 0;

};


class AbstractUi : public QObject {
  Q_OBJECT

  public:
    virtual void init() {};  // called after the client is initialized
    virtual MessageModel *createMessageModel(QObject *parent = 0) = 0;
    virtual AbstractUiMsg *layoutMsg(const Message &) = 0;

  protected slots:
    virtual void connectedToCore() {}
    virtual void disconnectedFromCore() {}

  signals:
    void connectToCore(const QVariantMap &connInfo);
    void disconnectFromCore();

};



#endif
