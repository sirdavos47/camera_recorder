#include <opencv2/opencv.hpp>
#include <iostream>

void show_usage() {
    std::cout << "Kullanım:\n"
              << "  camera_recorder live <ip_url>         # Canlı izleme\n"
              << "  camera_recorder record <ip_url> <output_file>  # Kaydet\n"
              << "  camera_recorder play <video_file>     # Oynat\n";
}

int main(int argc, char** argv) {
    if (argc < 3) {
        show_usage();
        return 1;
    }
    std::string mode = argv[1];
    if (mode == "live") {
        std::string ip_url = argv[2];
        cv::VideoCapture cap(ip_url);
        if (!cap.isOpened()) {
            std::cerr << "Kamera açılamadı!" << std::endl;
            return 1;
        }
        cv::Mat frame;
        while (true) {
            cap >> frame;
            if (frame.empty()) break;
            cv::imshow("Canlı İzleme", frame);
            if (cv::waitKey(30) == 27) break; // ESC ile çık
        }
    } else if (mode == "record" && argc >= 4) {
        std::string ip_url = argv[2];
        std::string output_file = argv[3];
        cv::VideoCapture cap(ip_url);
        if (!cap.isOpened()) {
            std::cerr << "Kamera açılamadı!" << std::endl;
            return 1;
        }
        int fourcc = cv::VideoWriter::fourcc('M','J','P','G');
        double fps = cap.get(cv::CAP_PROP_FPS);
        if (fps <= 0) fps = 25.0;
        int width = (int)cap.get(cv::CAP_PROP_FRAME_WIDTH);
        int height = (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT);
        cv::VideoWriter writer(output_file, fourcc, fps, cv::Size(width, height));
        if (!writer.isOpened()) {
            std::cerr << "Video dosyası oluşturulamadı!" << std::endl;
            return 1;
        }
        cv::Mat frame;
        auto start = std::chrono::steady_clock::now();
        while (true) {
            cap >> frame;
            if (frame.empty()) break;
            // Geçen süreyi hesapla
            auto now = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
            int minutes = elapsed / 60;
            int seconds = elapsed % 60;
            char time_str[16];
            snprintf(time_str, sizeof(time_str), "%02d:%02d", minutes, seconds);
            // Süreyi görüntüye yaz
            cv::putText(frame, time_str, cv::Point(20, 40), cv::FONT_HERSHEY_SIMPLEX, 1.2, cv::Scalar(0,255,0), 2);
            writer.write(frame);
            cv::imshow("Kayıt (ESC ile çık)", frame);
            if (cv::waitKey(30) == 27) break;
        }
    } else if (mode == "play" && argc >= 3) {
        std::string video_file = argv[2];
        cv::VideoCapture cap(video_file);
        if (!cap.isOpened()) {
            std::cerr << "Video açılamadı!" << std::endl;
            return 1;
        }
        cv::Mat frame;
        while (true) {
            cap >> frame;
            if (frame.empty()) break;
            cv::imshow("Oynatma", frame);
            if (cv::waitKey(30) == 27) break;
        }
    } else {
        show_usage();
        return 1;
    }
    return 0;
}
