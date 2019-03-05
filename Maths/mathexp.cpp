#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;

/*
	 Function to calculate the volume of a cube
		Takes a parameter that is the side of the cube
		returns the volume of the cube.
*/
float CubeVolume(float fSide)
{
	float fVolume=pow(fSide,3);
	return fVolume;
}

float SphereVolume(float fRadius)
{
	float fVolume=((4.0/3.0))*(M_PI*CubeVolume(fRadius));
	return fVolume;
}

float ConeVolume(float fRadius, float fHeight)
{
	float fVolume=0.0;
	fVolume=(M_PI)*(pow(fRadius,2))*((fHeight/3.0));
	return fVolume;
}


int main(int argc, char *argv[])
{
	float cubeSide = 5.4;
	float sphereRadius = 2.33;
	float coneRadius= 7.65;
	float coneHeight=14.0;
	float volCube, volSphere, volCone = 0.0;

	volCube=CubeVolume(cubeSide);
	volSphere=SphereVolume(sphereRadius);
	volCone=ConeVolume(coneRadius,coneHeight);

	cout << "The volume of the cube is: " << volCube << "\n";
	cout << "The volume of the sphere is: " << volSphere << "\n";
	cout << "The volume of the cone is: " << volCone << "\n";

	return 0;
}
