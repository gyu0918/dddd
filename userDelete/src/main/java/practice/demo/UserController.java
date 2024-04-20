package practice.demo;

import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.Map;
import java.util.Optional;

@RestController
@RequestMapping("/api/users")
@RequiredArgsConstructor
public class UserController {
    private final UserDeleteRepository userDeleteRepository;

    @DeleteMapping("/delete")
    public ResponseEntity<Map<String, Integer>> deleteUser(@RequestBody Map<String, String> req){
        String name = req.get("name");
        String email = req.get("email");
        String phoneCall = req.get("phoneCall");

        Optional<User> userOptional = userDeleteRepository.findByEmail(email);
        if (userOptional.isPresent() && userOptional.get().getName().equals(name)){
            userDeleteRepository.delete(userOptional.get());        // delete 기능을 사용하고 싶기 떄문에 repository이용
            Map<String, Integer> response = new HashMap<>();
            response.put("code", 200);
            return ResponseEntity.ok(response);
        }else{
            Map<String, Integer> response = new HashMap<>();
            response.put("code", 404);
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(response);
        }
    }
}
