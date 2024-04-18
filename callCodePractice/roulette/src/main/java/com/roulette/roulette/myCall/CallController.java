package com.roulette.roulette.myCall;

import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/css")
@RequiredArgsConstructor
public class CallController {

    private final CallService CallService;

    @PostMapping
    public ResponseEntity<Map<String, Integer>> saveCode(@RequestPart("code_file") MultipartFile codeFile,
                                                         @RequestPart("json") MemberIdDto memberIdDto) {
        Long memberId = memberIdDto.getMemberId();
        codeService.saveCode(codeFile, memberId);
        Map<String, Integer> response = new HashMap<>();
        response.put("code", 200);
        return ResponseEntity.ok(response);
    }
}

// DTO 클래스
@Data
public class MemberIdDto {
    private Long memberId;
}