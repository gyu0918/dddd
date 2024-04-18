package com.roulette.roulette.myCall;


import org.springframework.stereotype.Service;

@Service
public class CallService{

    private final CodeRepository codeRepository;

    @Autowired
    public CodeService(CodeRepository codeRepository) {
        this.codeRepository = codeRepository;
    }

    public void saveCode(MultipartFile codeFile, Long memberId) {
        try {
            Code code = new Code();
            code.setMemberId(memberId);
            code.setFileName(codeFile.getOriginalFilename());
            code.setContent(new String(codeFile.getBytes()));
            codeRepository.save(code);
        } catch (IOException e) {
            // handle exception
        }
    }
}