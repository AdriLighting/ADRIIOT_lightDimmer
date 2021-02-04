#include "lightDimmer.h"
#include <adri_tools_v2.h>

#define MAX_MODULE 10

lightDimmerClass 	* lightDimmerClassArray[MAX_MODULE];

lightDimmerManagment::lightDimmerManagment(){

}

void lightDimmerManagment::create(int value, int & result){
	lightDimmerClassArray[_pos] = new lightDimmerClass(value);
	result = _pos;
	_pos++;
}

void lightDimmerManagment::setPullup(boolean value){
	for (int i = 0; i < _pos; ++i) {lightDimmerClassArray[i]->setPullup(value);}
}

void lightDimmerManagment::setPullup(int pos, boolean value){
	lightDimmerClassArray[pos]->setPullup(value);
}

lightDimmerClass * lightDimmerManagment::module(int pos){
	return lightDimmerClassArray[pos];
}


lightDimmerClass::lightDimmerClass(int pin){
    _pin = pin;
    // pinMode(_pin ,OUTPUT);
    close();
}

void lightDimmerClass::close(){
    setStatus(false);
    _status = false;
    _nValue = 0;
}

void lightDimmerClass::open(){
    setStatus(true);
    _status = true;
    _nValue = 1;
}

void lightDimmerClass::toggle(){
    _status = !_status;
    setStatus(_status);
}

void lightDimmerClass::dim(int value){
	_analogValue = map(value,0,100,1024,0);
	analogWrite(_pin, _analogValue);
	_status = true;
	_nValue = 2;
}

void lightDimmerClass::setStatus(boolean value){
	if (value) {
		if (_pullup) 	{analogWrite(_pin , _analogValue);}
		else 			{digitalWrite(_pin, HIGH);}
	} else {
		if (_pullup) 	{digitalWrite(_pin, HIGH);}
		else 			{analogWrite(_pin , _analogValue);}
	}
	
}
void lightDimmerClass::setPullup(boolean value){
	_pullup = value;
}

void lightDimmerClass::getStatus(boolean & ret){
	ret = _status;
}
void lightDimmerClass::json(JsonObject & root){
	boolean ret;
	getStatus(ret);
	root[F("v1")] = ret;
	root[F("v2")] = String(_analogValue) ;
}
void lightDimmerClass::domoticzJson(JsonObject & root){
	boolean ret;
	getStatus(ret);
	
	root[F("nvalue")] = _nValue;
	root[F("svalue")] = String(map(_analogValue,0,1024,100,0));
}