/*
 * untitled.cxx
 * 
 * Copyright 2013  <pi@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "servoguic.h"
#include "ui_servoguic.h"
#include <QString>
#include <ctime>
#include <thread>
#include <cstdio>

using namespace std;

int angles=150;

int cservod()
{system ("sudo killall servod");
    return 0;

}


int setServo (int angle)
{
	angles = angle;
	string cmd;
	string sangle= std::to_string(angle);
    cmd="echo 1=" + sangle + " > /dev/servoblaster" ;
	char * ccmd = new char [cmd.length()+1];
	strcpy (ccmd, cmd.c_str());
	system (ccmd);
	//cout << ccmd;
	return angles ; 
	
}

int ledOn ()
{
    int led1 = 250 ;
    string cmd;
    string sled= std::to_string(led1);
    cmd="echo 5=" + sled + " > /dev/servoblaster" ;
    char * ccmd = new char [cmd.length()+1];
    strcpy (ccmd, cmd.c_str());
    system (ccmd);
    //cout << ccmd;
    return led1 ;

}

int ledOff ()
{
    int led1 = 0 ;
    string cmd;
    string sled= std::to_string(led1);
    cmd="echo 5=" + sled + " > /dev/servoblaster" ;
    char * ccmd = new char [cmd.length()+1];
    strcpy (ccmd, cmd.c_str());
    system (ccmd);
    //cout << ccmd;
    return led1 ;
}
int servoGuiC::right()
{
    float delay_period=atoi(ui ->lineEdit ->text().toStdString().c_str());
    //float delay_period ;
    //cout<< "Introduzca Delay:" ;
    //cin >> delay_period;
    int angles1;
    angles1 = (240-angles)/5 ;
    //cout<<angles1;
    int angles2;
    angles2=angles;
    time_t start =time(0);
    for (int angle=0 ;( angle<(angles1+1));++angle)
    {
        setServo(angles2+(angle*5));
        sleep(delay_period);


        string sang1= std::to_string(angles/100.0);

        char * ccang = new char [sang1.length()+1];
        strcpy (ccang, sang1.c_str());

        printf(ccang);
        //cout << (angles/100.0) << endl;
        QString ang = QString::number(angles/100.0);
        QString sang= "Pulde Widht="+ang + "ms";
        servoGuiC:: ui->textEdit ->append(sang);

    }
    time_t end=time(0);
    QString time = QString::number(difftime(end,start) );
    QString stime= "--------------------------------------\nOperation Finished at="+time + "seg";
    servoGuiC:: ui->textEdit ->append(stime);

    return 0;
}


	
int servoGuiC::left ()
{
    float delay_period=atoi(ui ->lineEdit ->text().toStdString().c_str());
    //float delay_period ;
    //cout<< "Introduzca Delay:" ;
    //cin >> delay_period;
	int angles1;
	angles1 = (angles -50)/5;
	int angles2; 
	angles2 = angles;
    time_t start =time(0);
	for (int angle=0 ;( angle<(angles1+1));++angle)
	{
		setServo(angles2-(angle*5));
        sleep(delay_period);
        string sang1= std::to_string(angles/100.0);

        char * ccang = new char [sang1.length()+1];
        strcpy (ccang, sang1.c_str());

        printf(ccang);
        //cout << (angles/100.0) << endl;
        QString ang = QString::number(angles/100.0);
        QString sang= "Pulde Widht="+ang + "ms";
        servoGuiC:: ui->textEdit ->append(sang);
	}
    time_t end=time(0);
    QString time = QString::number(difftime(end,start) );
    QString stime= "--------------------------------------\nOperation Finished at="+time + "seg";
    servoGuiC:: ui->textEdit ->append(stime);
	return 0;
	
}

int servoGuiC::center()
{
    float delay_period=atoi(ui ->lineEdit ->text().toStdString().c_str());
    //float delay_period ;
    //cout<< "Introduzca Delay:" ;
    //cin >> delay_period;
	int angles1;
	int angles2; 
	angles2 = angles;
    time_t start =time(0);
	if (angles>150)
	{
		angles1=(angles-150)/5;
		for (int angle=0 ;( angle<(angles1+1));++angle)
		{
			setServo(angles2-(angle*5));
			sleep(delay_period);
            string sang1= std::to_string(angles/100.0);

            char * ccang = new char [sang1.length()+1];
            strcpy (ccang, sang1.c_str());

            printf(ccang);

            QString ang = QString::number(angles/100.0);
            QString sang= "Pulde Widht="+ang + "ms";
            servoGuiC:: ui->textEdit ->append(sang);
	}}
	else 
	{
		angles1 = (150-angles)/5 ;
		for (int angle=0 ;( angle<(angles1+1));++angle)
		{
			setServo(angles2+(angle*5));
			sleep(delay_period);
            string sang1= std::to_string(angles/100.0);

            char * ccang = new char [sang1.length()+1];
            strcpy (ccang, sang1.c_str());

            printf(ccang);
            //cout << (angles/100.0) << endl;
            QString ang = QString::number(angles/100.0);
            QString sang= "Pulde Widht="+ang + "ms";
            servoGuiC:: ui->textEdit ->append(sang);
	}
	}
    time_t end=time(0);
    QString time = QString::number(difftime(end,start) );
    QString stime= "--------------------------------------\nOperation Finished at="+time + "seg";
    servoGuiC:: ui->textEdit ->append(stime);
	return 0;
	
}
