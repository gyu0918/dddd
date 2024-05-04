package mapPractice.findMap;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class PharmacyController {

    private final PharmacyService pharmacyService;

    public PharmacyController(PharmacyService pharmacyService) {
        this.pharmacyService = pharmacyService;
    }

    @GetMapping("/pharmacies")
    public List<Pharmacy> getPharmacies() {
        // 약국 정보를 가져오는 메서드 호출
        return pharmacyService.searchPharmacies(37.504622, 127.027497, 20000);
    }
}