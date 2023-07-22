package hello.core.beanfind;

import hello.core.AppConfig;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.config.BeanDefinition;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;

class ApplicationContextInfoTest {
    AnnotationConfigApplicationContext ac  = new AnnotationConfigApplicationContext(AppConfig.class);

    @Test
    @DisplayName("모든 빈 출력하기")
    void findAllBean(){
        String[] beanDefinitionNames = ac.getBeanDefinitionNames();
        for (String beanDefinitionName : beanDefinitionNames) {               //iter + tab 누르면 자동으로 for문생성
            Object bean = ac.getBean(beanDefinitionName);                     // type이 분명하지 않을경우 Object로?
            System.out.println("name = " + beanDefinitionName + "object = " + bean);
        }
    }
    @Test
    @DisplayName("임의로 등록한 빈만 출력하기")
    void findApplicationBean(){
        String[] beanDefinitionNames = ac.getBeanDefinitionNames();
        for (String beanDefinitionName : beanDefinitionNames) {               //iter + tab 누르면 자동으로 for문생성
            BeanDefinition beanDefinition = ac.getBeanDefinition(beanDefinitionName);

            if (beanDefinition.getRole() == BeanDefinition.ROLE_APPLICATION) {    //등록한 빈만 의미
                Object bean = ac.getBean(beanDefinitionName);
                System.out.println("name = " + beanDefinitionName + "object = " + bean);
            }
        }
    }
}
