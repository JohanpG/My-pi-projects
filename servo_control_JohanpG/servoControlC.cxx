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

using namespace std;
int angles=150;



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

int right ()
{
	float delay_period ;
	cout<< "Introduzca Delay:" ;
	cin >> delay_period;
	int angles1;
	angles1 = (250-angles)/5 ;
	//cout<<angles1;
	int angles2;
	angles2=angles;
	for (int angle=0 ;( angle<(angles1+1));++angle)
	{
		setServo(angles2+(angle*5));
		sleep(delay_period);
		cout << (angles/100.0) << endl;
	}
	
	return 0;
}
	
int left ()
{
	float delay_period ;
	cout<< "Introduzca Delay:" ;
	cin >> delay_period;
	int angles1;
	angles1 = (angles -50)/5;
	int angles2; 
	angles2 = angles;
	for (int angle=0 ;( angle<(angles1+1));++angle)
	{
		setServo(angles2-(angle*5));
		sleep(delay_period);
		cout << (angles/100.0) << endl;
	}
	return 0;
	
}

int center ()
{
	
	float delay_period ;
	cout<< "Introduzca Delay:" ;
	cin >> delay_period;
	int angles1;
	int angles2; 
	angles2 = angles;
	if (angles>150)
	{
		angles1=(angles-150)/5;
		for (int angle=0 ;( angle<(angles1+1));++angle)
		{
			setServo(angles2-(angle*5));
			sleep(delay_period);
			cout << (angles/100.0) << endl;
	}}
	else 
	{
		angles1 = (150-angles)/5 ;
		for (int angle=0 ;( angle<(angles1+1));++angle)
		{
			setServo(angles2+(angle*5));
			sleep(delay_period);
			cout << (angles/100.0) << endl;
	}
	}
	return 0;
	
}


	
int main() {
	system("sudo ./servod");
	
	setServo (150);
	right();
	
	left();
	
	center();

	return 0;
};
