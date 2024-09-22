#include "SmartCar.h"
#include <iostream>
#include <fstream>

const std::string SmartCar::defaultChassisId = "dp00001A";
const std::string SmartCar::defaultChassisModel = "SCOUT MINI";
const int SmartCar::defaultWheelBase = 451;
const int SmartCar::defaultWheelTrack = 490;
const int SmartCar::defaultGroundClearance = 115;
const int SmartCar::defaultTurningRadius = 0;
const std::string SmartCar::defaultDriveType = "四轮四驱";
const int SmartCar::defaultMaxRange = 10;
const std::string SmartCar::defaultTireModel1 = "公路轮";
const std::string SmartCar::defaultTireModel2 = "麦克纳姆轮";
const int SmartCar::defaultTireSize = 175;
const std::string SmartCar::defaultAgxModel = "AGX Xavier";
const int SmartCar::defaultAi = 32;
const int SmartCar::defaultCudaCores = 512;
const int SmartCar::defaultTensorCores = 64;
const int SmartCar::defaultMemorySize = 32;
const int SmartCar::defaultStorageSize = 32;
const std::string SmartCar::defaultCameraModel = "RealSense D435i";
const std::string SmartCar::defaultCameraFrameResolution = "1920*1080";
const int SmartCar::defaultCameraFrameRate = 30;
const std::string SmartCar::defaultCameraFov = "87*58";
const int SmartCar::defaultDepthFrameRate = 90;
const std::string SmartCar::defaultLidarModel = "RS-Helios-16p";
const int SmartCar::defaultLidarChannels = 16;
const int SmartCar::defaultLidarRange = 100;
const int SmartCar::defaultLidarPower = 8;
const std::string SmartCar::defaultGyroModel = "CH110";
const std::string SmartCar::defaultGyroManufacturer = "NXP";
const double SmartCar::defaultDisplaySize = 11.6;
const std::string SmartCar::defaultDisplayModel = "super";
const std::string SmartCar::defaultBatteryParameter = "24V/15Ah";
const int SmartCar::defaultBatterySupply = 24;
const int SmartCar::defaultChargeTime = 2;

SmartCar::SmartCar(const std::string& id) : id(id) {}

void SmartCar::setStudentId(const std::string& studentId) {
    this->studentId = studentId;
}

void SmartCar::setStudentName(const std::string& studentName) {
    this->studentName = studentName;
}

void SmartCar::saveToFile(const std::string& fileName) const {
    std::ofstream outFile(fileName, std::ios::out | std::ios::binary);
    if (outFile.is_open()) {
        outFile << "ID: " << id << std::endl;
        outFile << "底盘编号: " << defaultChassisId << std::endl;
        outFile << "底盘型号: " << defaultChassisModel << std::endl;
        outFile << "轴距: " << defaultWheelBase << "mm" << std::endl;
        outFile << "轮距: " << defaultWheelTrack << "mm" << std::endl;
        outFile << "最小离地间隙: " << defaultGroundClearance << "mm" << std::endl;
        outFile << "最小转弯半径: " << defaultTurningRadius << "m" << std::endl;
        outFile << "驱动形式: " << defaultDriveType << std::endl;
        outFile << "最大行程: " << defaultMaxRange << "KM" << std::endl;
        outFile << "轮胎型号1: " << defaultTireModel1 << std::endl;
        outFile << "轮胎型号2: " << defaultTireModel2 << std::endl;
        outFile << "轮胎尺寸: " << defaultTireSize << "mm" << std::endl;
        outFile << "AGX型号: " << defaultAgxModel << std::endl;
        outFile << "AI性能: " << defaultAi << " TOPS" << std::endl;
        outFile << "CUDA核心: " << defaultCudaCores << std::endl;
        outFile << "Tensor CORE: " << defaultTensorCores << std::endl;
        outFile << "显存: " << defaultMemorySize << "G" << std::endl;
        outFile << "存储: " << defaultStorageSize << "G" << std::endl;
        outFile << "摄像头型号: " << defaultCameraModel << std::endl;
        outFile << "摄像头帧分辨率: " << defaultCameraFrameResolution << std::endl;
        outFile << "摄像头帧率: " << defaultCameraFrameRate << std::endl;
        outFile << "FOV: " << defaultCameraFov << std::endl;
        outFile << "深度帧率: " << defaultDepthFrameRate << std::endl;
        outFile << "激光雷达型号: " << defaultLidarModel << std::endl;
        outFile << "激光雷达通道数: " << defaultLidarChannels << std::endl;
        outFile << "激光雷达测试范围: " << defaultLidarRange << "m" << std::endl;
        outFile << "激光雷达功耗: " << defaultLidarPower << "W" << std::endl;
        outFile << "陀螺仪型号: " << defaultGyroModel << std::endl;
        outFile << "陀螺仪厂家: " << defaultGyroManufacturer << std::endl;
        outFile << "液晶显示屏尺寸: " << defaultDisplaySize << std::endl;
        outFile << "液晶显示屏型号: " << defaultDisplayModel << std::endl;
        outFile << "电池参数: " << defaultBatteryParameter << std::endl;
        outFile << "对外供电: " << defaultBatterySupply << "V" << std::endl;
        outFile << "充电时长: " << defaultChargeTime << "H" << std::endl;
        outFile << "学生ID: " << studentId << std::endl;
        outFile << "学生姓名: " << studentName << std::endl;
        outFile.close();
    } else {
        std::cerr << "无法打开文件进行写入: " << fileName << std::endl;
    }
}

SmartCar SmartCar::loadFromFile(const std::string& fileName) {
    std::ifstream inFile(fileName, std::ios::in | std::ios::binary);
    if (inFile.is_open()) {
        std::string id;
        std::string studentId;
        std::string studentName;
        std::string line;

        while (std::getline(inFile, line)) {
            if (line.find("ID: ") != std::string::npos) {
                id = line.substr(line.find("ID: ") + 4);
            } else if (line.find("学生ID: ") != std::string::npos) {
                studentId = line.substr(line.find("学生ID: ") + 8);
            } else if (line.find("学生姓名: ") != std::string::npos) {
                studentName = line.substr(line.find("学生姓名: ") + 10);
            }
        }
        inFile.close();

        SmartCar car(id);
        car.setStudentId(studentId);
        car.setStudentName(studentName);
        return car;
    } else {
        std::cerr << "无法打开文件进行读取: " << fileName << std::endl;
        return SmartCar("");
    }
}

void SmartCar::display() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "底盘编号: " << defaultChassisId << std::endl;
    std::cout << "底盘型号: " << defaultChassisModel << std::endl;
    std::cout << "轴距: " << defaultWheelBase << "mm" << std::endl;
    std::cout << "轮距: " << defaultWheelTrack << "mm" << std::endl;
    std::cout << "最小离地间隙: " << defaultGroundClearance << "mm" << std::endl;
    std::cout << "最小转弯半径: " << defaultTurningRadius << "m" << std::endl;
    std::cout << "驱动形式: " << defaultDriveType << std::endl;
    std::cout << "最大行程: " << defaultMaxRange << "KM" << std::endl;
    std::cout << "轮胎型号1: " << defaultTireModel1 << std::endl;
    std::cout << "轮胎型号2: " << defaultTireModel2 << std::endl;
    std::cout << "轮胎尺寸: " << defaultTireSize << "mm" << std::endl;
    std::cout << "AGX型号: " << defaultAgxModel << std::endl;
    std::cout << "AI性能: " << defaultAi << " TOPS" << std::endl;
    std::cout << "CUDA核心: " << defaultCudaCores << std::endl;
    std::cout << "Tensor CORE: " << defaultTensorCores << std::endl;
    std::cout << "显存: " << defaultMemorySize << "G" << std::endl;
    std::cout << "存储: " << defaultStorageSize << "G" << std::endl;
    std::cout << "摄像头型号: " << defaultCameraModel << std::endl;
    std::cout << "摄像头帧分辨率: " << defaultCameraFrameResolution << std::endl;
    std::cout << "摄像头帧率: " << defaultCameraFrameRate << std::endl;
    std::cout << "FOV: " << defaultCameraFov << std::endl;
    std::cout << "深度帧率: " << defaultDepthFrameRate << std::endl;
    std::cout << "激光雷达型号: " << defaultLidarModel << std::endl;
    std::cout << "激光雷达通道数: " << defaultLidarChannels << std::endl;
    std::cout << "激光雷达测试范围: " << defaultLidarRange << "m" << std::endl;
    std::cout << "激光雷达功耗: " << defaultLidarPower << "W" << std::endl;
    std::cout << "陀螺仪型号: " << defaultGyroModel << std::endl;
    std::cout << "陀螺仪厂家: " << defaultGyroManufacturer << std::endl;
    std::cout << "液晶显示屏尺寸: " << defaultDisplaySize << std::endl;
    std::cout << "液晶显示屏型号: " << defaultDisplayModel << std::endl;
    std::cout << "电池参数: " << defaultBatteryParameter << std::endl;
    std::cout << "对外供电: " << defaultBatterySupply << "V" << std::endl;
    std::cout << "充电时长: " << defaultChargeTime << "H" << std::endl;
    std::cout << "学生ID: " << studentId << std::endl;
    std::cout << "学生姓名: " << studentName << std::endl;
}

