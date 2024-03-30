package hello.springmvc.basic;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.net.Socket;
//@Controller -> ㅇㅣ거를 쓸거면 return 에 view가 되어야 한다.
@RestController   //RestApi의 핵심
public class LogTestController {
    private final Logger log = LoggerFactory.getLogger(getClass());

    @RequestMapping("/log-test")
    public String logTest(){
        String name = "Spring";
        System.out.println("name = " + name);
        log.info("info log={}", name);
        return "ok";
    }
}
