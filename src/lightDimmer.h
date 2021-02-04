
#ifndef LIGHTDIMMER_H
	#define LIGHTDIMMER_H
	#include <Arduino.h>
	#include <ArduinoJson.h>

	class lightDimmerClass
	{
	public:
		lightDimmerClass(int pin);
		~lightDimmerClass();

	    void 	open();
	    void 	close();
	    void 	toggle();
	    void 	dim(int value);

	    void 	setStatus(boolean value);
	    void 	setPullup(boolean value);

	    void	getStatus(boolean & ret);

	    void 	json(JsonObject & root);
	    void 	domoticzJson(JsonObject & root);

	private:
	    boolean 	_pullup = true;
	    int 		_pin;
	    boolean		_status;	
	    int			_analogValue = 0;
	    int 		_nValue = 0;
	};


	class lightDimmerManagment
	{
	private:
		int _pos = 0;
	public:
		lightDimmerManagment();
		~lightDimmerManagment(){};

		void create 	(int value, int & result);

		void setPullup 	(boolean value);
		void setPullup 	(int pos, boolean value);

		lightDimmerClass * module(int pos);
	};

#endif // RELAY_H