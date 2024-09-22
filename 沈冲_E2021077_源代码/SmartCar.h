#ifndef SMARTCAR_H
#define SMARTCAR_H

#include <string>
#include <vector>

class SmartCar {
public:
    SmartCar(const std::string& id);

    void setStudentId(const std::string& studentId);
    void setStudentName(const std::string& studentName);
    void saveToFile(const std::string& fileName) const;
    static SmartCar loadFromFile(const std::string& fileName);

    void display() const;

private:
    std::string id;
    std::string studentId;
    std::string studentName;
    static const std::string defaultChassisId;
    static const std::string defaultChassisModel;
    static const int defaultWheelBase;
    static const int defaultWheelTrack;
    static const int defaultGroundClearance;
    static const int defaultTurningRadius;
    static const std::string defaultDriveType;
    static const int defaultMaxRange;
    static const std::string defaultTireModel1;
    static const std::string defaultTireModel2;
    static const int defaultTireSize;
    static const std::string defaultAgxModel;
    static const int defaultAi;
    static const int defaultCudaCores;
    static const int defaultTensorCores;
    static const int defaultMemorySize;
    static const int defaultStorageSize;
    static const std::string defaultCameraModel;
    static const std::string defaultCameraFrameResolution;
    static const int defaultCameraFrameRate;
    static const std::string defaultCameraFov;
    static const int defaultDepthFrameRate;
    static const std::string defaultLidarModel;
    static const int defaultLidarChannels;
    static const int defaultLidarRange;
    static const int defaultLidarPower;
    static const std::string defaultGyroModel;
    static const std::string defaultGyroManufacturer;
    static const double defaultDisplaySize;
    static const std::string defaultDisplayModel;
    static const std::string defaultBatteryParameter;
    static const int defaultBatterySupply;
    static const int defaultChargeTime;
};

#endif // SMARTCAR_H