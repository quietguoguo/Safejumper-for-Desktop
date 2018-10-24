/***************************************************************************
 *   Copyright (C) 2017 by Jeremy Whiting <jeremypwhiting@gmail.com>       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.                *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 ***************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "common.h"

#include <QNetworkReply>
#include <QQuickView>

class QNetworkAccessManager;
class QProgressDialog;

class MainWindow : public QQuickView
{
    Q_OBJECT
public:

    ~MainWindow();
    static bool exists();
    static MainWindow *instance();
    static void cleanup();

    void showFeedback();
    void showConnection();

public slots:
    void portDialogResult(bool cyclePort);

    void showAndFocus();
    void showLogs();
    void showMap();
    void showSettings();

    void languageChanged();

    void showConfirmation(const QString &text);

    void closeWindow();

    void shutDown();

signals:
    void confirmExit();

protected:
    virtual void closeEvent(QCloseEvent * event);

private slots:
    // Feedback page slots
    void on_sendFeedbackButton_clicked();
    void on_cancelFeedbackButton_clicked();

    void postError(QNetworkReply::NetworkError error);
    void sendFeedbackFinished();

private:
    static QPointer<MainWindow> mInstance;
    explicit MainWindow();

    // Feedback page members
    QNetworkAccessManager *mNam;
    QProgressDialog *mProgressDialog;
};


#endif // CONNECTIONDIALOG_H
