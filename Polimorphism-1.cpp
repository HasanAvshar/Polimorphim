#include <iostream>
#include<cassert>
#include<vector>
using namespace std;

class Car {
	int _id;
	static int _StaticId;
	string* _model;
	string* _vendor;
	bool* _hasSpoiler;
	vector<string> models;
public:
	Car() {
		_id = _StaticId++;
		_model = nullptr;
		_vendor = nullptr;
		_hasSpoiler = nullptr;
	}
	Car(string model, string vendor, bool hasSpoiler) {
		_id = _StaticId++;
		SetModel(model);
		SetVendor(vendor);
		SetHasSpoiler(hasSpoiler);
	}

	Car* getCarById(size_t id) {
		for (size_t i = 0; i < models.size(); i++) {
			if (GetId() == id) {
				return this;
			}
		}

		return nullptr;
	}

	void AddModel(const string& model) {
		models.push_back(model);
	}

	void RemoveModel() {
		if (!models.empty()) {
			models.pop_back();
		}
		else { assert(!"Model is empty!"); }
	}

	int GetId() { return _id; }
	int GetStaticId() { return _StaticId; }
	string* GetModel() { return _model; }
	string* GetVendor() { return _vendor; }
	bool* GetHasSpoiler() { return _hasSpoiler; }

	static void SetStaticId(int value) {
		_StaticId = value;
	}
	void SetModel(string model) {
		if (model.size() > 4 && model.size() < 120)
			_model = new string(model);
		else { assert(!"Model minumum 4 maksimum 120 ola biler"); }
	}
	void SetVendor(string vendor) {
		if (vendor.size() >= 6 && vendor.size() < 200)
			_vendor = new string(vendor);
		else { assert(!"Vendor minumum 6 maksimum 200 ola biler"); }
	}
	void SetHasSpoiler(bool hasSpoiler) {
		if (hasSpoiler == true || hasSpoiler == false)
			_hasSpoiler = new bool(hasSpoiler);
		else { assert(!"Error!"); }
	}

	virtual void Print() {
		cout << "Id: " << _id << endl;
		cout << "Model: " << *_model << endl;
		cout << "Vendor: " << *_vendor << endl;
		cout << "HasSpoiler: " << (_hasSpoiler != nullptr ? (*_hasSpoiler ? "true" : "false") : "nullptr") << endl;
	}
	virtual ~Car() {
		if (_model != nullptr) delete _model;
		if (_vendor != nullptr) delete _vendor;
		if (_hasSpoiler != nullptr) delete _hasSpoiler;

		_model = nullptr;
		_vendor = nullptr;
		_hasSpoiler = nullptr;
	}
};

int Car::_StaticId = 1;

class Manual : public Car {
	bool* _Clutch;
	int* _Gear_Ratios;
	int* _engine;
public:
	Manual() {
		_Clutch = nullptr;
		_Gear_Ratios = nullptr;
		_engine = nullptr;
	}
	Manual(string model, string vendor, bool hasSpoiler, bool Clutch, int Gear_Ratios, int engine) :Car(model, vendor, hasSpoiler) {
		SetClutch(Clutch);
		SetGear_Ratios(Gear_Ratios);
		SetEngine(engine);
	}

	bool* GetClutch() { return _Clutch; }
	int* GetGear_Ratios() { return _Gear_Ratios; }
	int* GetEngine() { return _engine; }

	void SetClutch(bool Clutch) {
		if (Clutch == true || Clutch == false)
			_Clutch = new bool(Clutch);
		else { assert(!"Error!"); }
	}
	void SetGear_Ratios(int Gear_Ratios) {
		if (Gear_Ratios >= 1 && Gear_Ratios <= 8)
			_Gear_Ratios = new int(Gear_Ratios);
		else { assert(!"Gear Ratios minumum 1 maksimum 8 ola biler"); }
	}
	void SetEngine(int engine) {
		if (engine >= 100 && engine <= 500)
			_engine = new int(engine);
		else { assert(!"Engine minumum 100 maksimum 500 ola biler"); }
	}

	void Print() override {
		Car::Print();
		cout << "Clutch: " << (_Clutch != nullptr ? (*_Clutch ? "true" : "false") : "nullptr") << endl;
		cout << "Gear Ratios: " << *_Gear_Ratios << endl;
		cout << "Engine: " << *_engine << endl;
	}

	~Manual() override {
		if (_Clutch != nullptr) delete _Clutch;
		if (_Gear_Ratios != nullptr) delete _Gear_Ratios;
		if (_engine != nullptr) delete _engine;

		_Clutch = nullptr;
		_Gear_Ratios = nullptr;
		_engine = nullptr;
	}
};

class Automatic :public Car {
	int* _speed;
	bool* _camera;
public:
	Automatic() {
		_speed = nullptr;
		_camera = nullptr;
	}
	Automatic(bool hasSpoiler, int speed, bool camera, string model, string vendor) :Car(model, vendor, hasSpoiler) {
		SetSpeed(speed);
		SetCamera(camera);
	}

	int* GetSpeed() { return _speed; }
	bool* GetCamera() { return _camera; }

	void SetSpeed(int speed) {
		if (speed >= 1 && speed <= 300)
			_speed = new int(speed);
		else { assert(!"Speed minumum 1 maksimum 300 ola biler"); }
	}
	void SetCamera(bool camera) {
		if (camera == true || camera == false)
			_camera = new bool(camera);
		else { assert(!"Error!"); }
	}

	void Print() override {
		Car::Print();
		cout << *_speed << endl;
		cout << *_camera << endl;
	}
	~Automatic() override {
		if (_speed != nullptr) delete _speed;
		if (_camera != nullptr) delete _camera;

		_speed = nullptr;
		_camera = nullptr;
	}

};

class Bmw :public Automatic {
	string* _series;
	string* _modelType;
public:
	Bmw() {
		_series = nullptr;
		_modelType = nullptr;
	}
	Bmw(string series, string modelType, bool hasSpoiler, int speed, bool camera, string model, string vendor) : Automatic(hasSpoiler, speed, camera, model, vendor)
	{
		SetModelType(modelType);
		SetSeries(series);
	}

	string* GetSeries() { return _series; }
	string* GetModelType() { return _modelType; }

	void SetSeries(string series) {
		if (series.size() >= 2 && series.size() < 50)
			_series = new string(series);
		else {
			assert(!"Series minimum 2 maximum 50 characters allowed");
		}
	}

	void SetModelType(string modelType) {
		if (!modelType.empty())
			_modelType = new string(modelType);
		else {
			assert(!"Model type cannot be empty");
		}
	}

	void Print() override {
		Automatic::Print();
		cout << "Series: " << *_series << endl;
		cout << "Model Type: " << *_modelType << endl;
	}

	~Bmw() override {
		if (_series != nullptr) delete _series;
		if (_modelType != nullptr) delete _modelType;

		_series = nullptr;
		_modelType = nullptr;
	}
};
void main()
{
	Bmw bmwCar("3 Series", "Sedan", true, 250, true, "BMW Model XYZ", "BMW Vendor");

	bmwCar.SetSeries("3 Series");
	bmwCar.SetModelType("Sedan");

	bmwCar.Print();


}