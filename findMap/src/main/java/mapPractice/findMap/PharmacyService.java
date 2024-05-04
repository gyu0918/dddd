package mapPractice.findMap;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.*;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;

@Service
public class PharmacyService {

    @Value("${kakao.rest.api.key}")
    private String restApiKey;

    private final RestTemplate restTemplate;
    @Autowired // 이 부분 추가
    public PharmacyService(RestTemplate restTemplate) {
        this.restTemplate = restTemplate;
    }

    public List<Pharmacy> searchPharmacies(double latitude, double longitude, int radius) {
        String url = "https://dapi.kakao.com/v2/local/search/category.json" +
                "?category_group_code=PM9" +
                "&radius=" + radius +
                "&x=" + longitude +
                "&y=" + latitude;

        HttpHeaders headers = new org.springframework.http.HttpHeaders();
        headers.setAccept(Collections.singletonList(MediaType.APPLICATION_JSON));
        headers.set("Authorization", "KakaoAK " + restApiKey);

        HttpEntity<String> entity = new HttpEntity<>(headers);

        ResponseEntity<Map> responseEntity = restTemplate.exchange(url, HttpMethod.GET, entity, Map.class);

        if (responseEntity.getStatusCode() == HttpStatus.OK) {
            Map<String, Object> responseBody = responseEntity.getBody();
            if (responseBody != null && responseBody.containsKey("documents")) {
                List<Map<String, Object>> documents = (List<Map<String, Object>>) responseBody.get("documents");
                List<Pharmacy> pharmacies = new ArrayList<>();
                for (Map<String, Object> document : documents) {
                    Pharmacy pharmacy = new Pharmacy();
                    pharmacy.setPlaceName((String) document.get("place_name"));
                    pharmacy.setAddress((String) document.get("address_name"));
                    pharmacy.setRoadAddress((String) document.get("road_address_name"));
                    pharmacy.setPhone((String) document.get("phone"));
                    pharmacies.add(pharmacy);
                }
                return pharmacies;
            }
        }

        return Collections.emptyList();
    }

}
