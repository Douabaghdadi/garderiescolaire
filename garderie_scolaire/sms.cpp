#include "sms.h"


size_t SMS::writecallback(void* ptr, size_t size, size_t nmemb, void* userdata)
{
    ((std::string*)userdata)->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

SMS::SMS(std::string apiKey, std::string apiSecret, std::string fromNumber)
    : m_apiKey(apiKey), m_apiSecret(apiSecret), m_fromNumber(fromNumber)
{}

SMS::~SMS() {}

bool SMS::sendSMS(std::string toNumber, std::string message) {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {

        std::string url = "https://rest.nexmo.com/sms/json?api_key=d2c5ddf4&api_secret=bM0Z88a9OHbE9hDA&from=Vonage&to=+21621862359&text=Bienvenue%sur%notre%plateforme";

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writecallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return false;
        }
    }
    else {
        fprintf(stderr, "Failed to initialize curl\n");
        return false;
    }

    curl_global_cleanup();

    return true;
}
